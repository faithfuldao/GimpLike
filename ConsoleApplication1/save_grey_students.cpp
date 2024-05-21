#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{

    if (argc != 2)
    {
        printf("Usage: %s <path_to_image>\n", argv[0]);
        return -1;
    }

    char* imageName = argv[1];
    Mat image = imread(imageName);

    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    std::string fileName = "HappyFish2.jpg";

    bool isSuccess = imwrite(fileName, gray_image);
    if (!isSuccess)
    {
        printf("can't save image");
        return -1;
    }

    namedWindow("OriginalHappyFish", WINDOW_AUTOSIZE);
    namedWindow("GrayHappyFish", WINDOW_AUTOSIZE);

    imshow("OriginalHappyFish", image);
    imshow("GrayHappyFish", gray_image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}