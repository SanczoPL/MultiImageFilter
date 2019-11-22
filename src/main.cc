#include "../include/multiimagefilter.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    QJsonObject filterConfig{{"Name", "GaussianBlur"},
                             {"KernelSizeX", 15},
                             {"KernelSizeY", 15},
                             {"SigmaX", 3},
                             {"SigmaY", 3},
                             {"BorderType", 4}};

    QJsonObject filterConfig2{{"Name", "Color"}, {"ColorCode", 6}};

    QJsonObject filterConfig3{
    {"Name", "Resize"}, {"Width", 200}, {"Height", 200}};

    QJsonObject filterConfig4{{"Name", "MedianBlur"}, {"KernelSize", 9}};

    QJsonObject filterConfig5{{"Name", "MorphologyOperation"},
                                {"MorphOperator", 0},
                                {"MorphSize", 11},
                                {"MorphElement", 0}};

    QJsonObject filterConfig6{{"Name", "MorphologyOperation"},
                                {"MorphOperator", 1},
                                {"MorphSize", 11},
                                {"MorphElement", 0}};

    QJsonArray filters{filterConfig, filterConfig2};
    MultiImageFilter multiImageFilter{filterConfig6};
    cv::Mat image{cv::imread("example.jpeg")};
    cv::Mat image2{};
    image.copyTo(image2);

    multiImageFilter.process(image2);

    cv::imshow("Before", image);
    cv::imshow("After", image2);
    cv::waitKey(0);

    return 0;
}
