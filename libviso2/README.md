# Feature Matching
The input to our visual odometry algorithm are features matched between four images, namely the left and right images of two consecutive frames.

In order to find stable feature locations, we first filter the input images with 5 × 5 blob and corner masks, as given in Fig.
Next, we employ non-maximum- and non-minimum-suppression [20] on the filtered images, resulting in feature candidates which belong to one of four classes (i.e., blob max, blob min, corner max, corner min). 

To reduce computational efforts, we only match features within those classes. In contrast to methods concerned with reconstructions from unordered image collections, here we assume a smooth camera trajectory, superseding computationally intense rotation and scale invariant feature descriptors like SURF [4].

Given two feature points, we simply **compare 11 × 11 block windows of horizontal and vertical Sobel filter responses to each other** by using the sum of absolute differences (SAD) error metric. 

To speed-up matching, we quantize the Sobel responses to 8 bits and sum the differences over a sparse set of 16 locations (see Fig. 3(c)) instead of summing over the whole block window. Since the *SAD of 16 bytes* can be computed efficiently using a single SSE instruction we only need two calls (for horizontal + vertical Sobel responses) in order to evaluate this error metric.

> Sobel respenses is 8 bits, SSE instruction can accelerate 16 bytes datas. So one piece of SSE instruction can storage 16 8-bits datas. Then extract 16 points of  horizontal and vertical Sobel responses, SAD of each other need 2 SSE instruction (32 bytes).

Our egomotion estimation mechanism expects features to be matched between the left and right images and two consecutive frames. This is achieved by matching features in a ’circle’: 

1. Starting from all feature **candidates** in the current left image, we find the best match in the previous left image within a M × M search window
2. next in the previous right image, the current right image and last in the current left image again. 

A ’circle match’ gets accepted, if the last feature coincides with the first feature. When matching between the left and right images, we additionally make use of the epipolar constraint using *an error tolerance of 1 pixel*. 
> epipolar constraint is used for get R and t ?

Sporadic outliers are removed by establishing neighborhood relations as edges of a 2d Delaunay triangulation [25] on the feature locations in the current left image. 
> left neighborhood relations means edge of 2d Delaunay triangulation?

We only retain matches which are supported by at least two neighboring matches, where a match is supporting another match, if its disparity and flow differences fall within some threshold τ<sub>disp</sub> or τ<sub>flow</sub> respectively. 

If required, sub-pixel refinement via parabolic fitting can be employed to further improve feature localization. Even though our implementation is very efficient, establishing several thousands to ten thousands of correspondences still takes time in the order of seconds, hence making it too slow for online applications.

By transferring ideas already employed in previous works on stereo matching [12], further significant speed-ups are possible: 

1. In a first pass, we match only a **subset** of all features, found by non-maxima-suppression (NMS) using a larger NMS neighborhood size (factor 3). Since this subset is much smaller than the full feature set, matching is very fast. 
> what's the neighborhood size of NMS? 
> 非极大值抑制（Non-Maximum Suppression，NMS），顾名思义就是抑制不是极大值的元素，可以理解为局部最大搜索。这个局部代表的是一个邻域，邻域有两个参数可变，一是邻域的维数，二是邻域的大小。**TODO:Read NMS.**

2. Next, we assign each feature in the current left image to a 50 × 50 pixel bin of an equally spaced grid. Given all sparse feature matches, we compute the minimum and maximum displacements for each bin. 

Those statistics are used to locally narrow down the final search space, leading to faster matching and a higher number of matches at the same time, as evidenced in the experimental section. Fig. 4 illustrates feature matching and tracking results using our method.

# Egomotion Estimation
Given all ’circular’ feature matches from the previous section, we compute the camera motion by minimizing the sum of reprojection errors and refining the obtained velocity estimates by means of a Kalman filter. 

First, bucketing is used to reduce the number of features (in practice we retain between 200 and 500 features) and spread them uniformly over the image domain. 

Next, we project feature points from the **previous frame** into 3d via triangulation using the calibration parameters of the stereo camera rig. Assuming squared pixels and zero skew, the reprojection into the current image is given by with
- homogeneous image coordinates (u v 1)<sup>T</sup>
- focal length f
- principal point (c<sub>u</sub>,<sub>cv</sub>)
- rotation matrix R(r) = R<sub>x</sub>(r<sub>x</sub>)R<sub>y</sub>(r<sub>y</sub>)R<sub>z</sub>(r<sub>z</sub>)
- translation vector t = (t<sub>x</sub> t<sub>y</sub> t<sub>z</sub>)<sup>T</sup>
- 3d point coordinates X = (x y z)<sup>T</sup>
- and shift s = 0 (left image), s = baseline (right image).
Let now π(l)(X; r, t) : R3 → R2 denote the projection
implied by Eq. 1, which takes a 3d point X and maps it
to a pixel x(l)
i ∈ R2 on the left image plane. Similarly, let
π(r)(X; r,t) be the projection onto the right image plane.
Using Gauss-Newton optimization, we iteratively minimize
N∑
i=1
∥∥∥x(l)
i −π(l)(Xi; r,t)
∥∥∥2
+
∥∥∥x(r)
i −π(r)(Xi; r,t)
∥∥∥2
(2)
with respect to the transformation parameters (r,t). Here
x(l)
i and x(r)
i de