# Feature Matching
The input to our visual odometry algorithm are features matched between four images, namely the left and right images of two consecutive frames.
In order to find stable feature locations, we first filter the input images with 5 × 5 blob and corner masks, as given in Fig.
Next, we employ non-maximum- and non-minimum-suppression [20] on the filtered images, resulting in feature candidates which belong to one of four classes (i.e., blob max, blob min, corner max, corner min). 
To reduce computational efforts, we only match features within those classes. In contrast to methods concerned with reconstructions from unordered image collections, here we assume a smooth camera trajectory, superseding computationally intense rotation and scale invariant feature descriptors like SURF [4].
Given two feature points, we simply **compare 11 × 11 block windows of horizontal and vertical Sobel filter responses to each other** by using the sum of absolute differences (SAD) error metric. 
To speed-up matching, we quantize the Sobel responses to 8 bits and sum the differences over a sparse set of 16 locations (see Fig. 3(c)) instead of summing over the whole block window. Since the *SAD of 16 bytes* can be computed efficiently using a single SSE instruction we only need two calls (for horizontal + vertical Sobel responses) in order to evaluate this error metric.

> Sobel respenses is 8 bits, SSE instruction can accelerate 16 bytes data. So one piece of SSE instruction can storage 16 8-bits datas. Then extract 16 points of  horizontal and vertical Sobel responses, SAD of each other need 2 SSE instruction (32 bytes).

Our egomotion estimation mechanism expects features to be matched between the left and right images and two consecutive frames. This is achieved by matching features in a ’circle’: 

1. Starting from all feature **candidates** in the current left image, we find the best match in the previous left image within a M × M search window
2. next in the previous right image, the current right image and last in the current left image again. 

A ’circle match’ gets accepted, if the last feature coincides with the first feature. When matching between the left and right images, we additionally make use of the epipolar constraint using *an error tolerance of 1 pixel*. 
> epipolar constraint is used for get R and t ?

Sporadic outliers are removed by establishing neighborhood relations as edges of a *2d Delaunay triangulation* [25] on the feature locations in the current left image. 
> 2d Delaunay triangulation on current left image?

We only retain matches which are supported by *at least two neighboring matches*, where a match is supporting another match, if its disparity and flow differences fall within some threshold τ<sub>disp</sub>or<sub>τ</sub> flow respectively. 
> match 4 times is best?

If required, sub-pixel refinement via parabolic fitting can be employed to further improve feature localization. Even though our implementation is very efficient, establishing several thousands to ten thousands of correspondences still takes time in the order of seconds, hence making it too slow for online applications. By transferring ideas already employed in previous works on stereo matching [12], further significant speed-ups are possible: In a first pass, we match only a subset of all features, found by non-maxima suppression (NMS) using a larger NMS neighborhood size (factor 3). Since this subset is much smaller than the full feature set, matching is very fast. Next, we assign each feature in the current left image to a 50 × 50 pixel bin of an equally spaced grid. Given all sparse feature matches, we compute the minimum and maximum displacements for each bin. Those statistics are used to locally narrow down the final search space, leading to faster matching and a higher number of matches at the same time, as evidenced in the experimental section. Fig. 4 illustrates feature matching and tracking results using our method.
