# 2D image to 3D world triangulation
In this post I am interested in triangulation, the technique of inferring the 3D position of an object from two images of this object, taken from different viewpoints. The technique relies on the ability to find corresponding 2D points in two images. In this sense the triangulation is a 'poor man's' 3D location estimator.

2D point correspondence + Triangulation -> 3D location
The initial set up is below.

The steps which I preformed are below.
1. I assume that the camera is calibrated (focal length, principal point position in the image, distortion coefficients (as defined in OpenCV)).
2. To find the camera position for each image, I made the photo of a target object *together* with a calibration rig. Then OpenCV.solvePnP determines a camera position from the image of detected calibration rig.
> what is the effect of together?
3. Then I manually removed the outer portion of an image to keep the target object only. One reason is that the redundant image of the calibration rig is removed. Further this should be much rewarding for an estimation of corresponding points because the number of false positive matches is reduced.

4. Now there is only the target object in each image. I used VLFeat (http://www.vlfeat.org) library to find the point's correspondence in two images. It turns out that the number of detected corresponding points is too small for the majority of target objects which I tried to work with. Here I use one bright object with plenty of adornments. But even in this case I had to manually add a couple of corresponding points to better recover the original object's shape (in the picture below the manual points are on the left and right planes of the cube).

5. The 2D-to-3D triangulation algorithm takes camera orientation for both images and the set of corresponding 2D points. It outputs the 3D position per each pair of corresponding 2D points.

6. The set of 3D points is ready. But without color information such a sparse construction makes no visual sense. I split the set of 2D points in the first image into triangles using Delaunay triangulation. (Note: the Delaunay triangulation is used to split the space into triangles; in this post *I am describing triangulation as a way to find the 3D coordinates of the point* from a pair of 2D coordinates in two different images).
> triangulation is used for 3D coordinates?

The set of triangles in the first image defines the set of triangles in 3D space. I use the texture of a triangle in the first image to color the corresponding triangle in 3D space.

Results.
The search for corresponding points was performed using VLFeat library. I found that for relatively small objects, point's correspondence works only when image contains small elements of different color and have contrast edges. For smooth objects the corresponding points can't be determined and the triangulation is not achievable.
My thoughts are that RGB+D (plus depth) sensors are not just desirable but at least necessary for 3D reconstruction, because color based point's correspondence it two images is just too hard.
