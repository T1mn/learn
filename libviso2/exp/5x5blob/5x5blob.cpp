#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

using namespace cv;
int main()
{
    Mat src, blob, corner, combine;
    for (int32_t i=0; i<373; i++) {
    
        char base_name[256];
        sprintf(base_name, "%06d.png", i);
        std::string dir = "/home/toia/learn/libviso2/imgs/2010_03_09_drive_0019";
        std::string left_img_file_name = dir + "/I1_" + base_name;
        std::string right_img_file_name = dir + "/I2_" + base_name;

        src = imread(left_img_file_name);
        if (!src.data)
        {
            printf("could not load image...\n");
            return -1;
        }
        float scale = 0.6;
        resize(src, src, Size(src.cols * scale, src.rows * scale));
        Mat blobKernel = (Mat_<char>(5, 5) << -1, -1, -1, -1, -1,
                          -1, 1, 1, 1, -1,
                          -1, 1, 8, 1, -1,
                          -1, 1, 1, 1, -1,
                          -1, -1, -1, -1, -1);
        Mat cornerKernel = (Mat_<char>(5, 5) << -1, -1, 0, 1, 1,
                            -1, 1, 0, 1, 1,
                            0, 0, 0, 0, 0,
                            1, 1, 0, -1, -1,
                            1, 1, 0, -1, -1);
        filter2D(src, blob, src.depth(), blobKernel);
        putText(blob, "blob", Point2d(10, 30), 3, 1, Scalar(255, 100, 100));
        filter2D(src, corner, src.depth(), cornerKernel);
        putText(corner, "corner", Point2d(10, 30), 3, 1, Scalar(255, 100, 100));
        vconcat(blob, corner, combine);
        vconcat(src, combine, combine);
        imshow("combine", combine);
        waitKey(0);
    }
    return 0;
}