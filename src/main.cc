#include "../src/multiimagefilter.h"
#include <QDebug>
#include <iostream>
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

    QJsonObject filterConfig7{{"Name", "BilateraFilter"},
                                {"Diameter", 50},
                                {"SigmaColor", 150},
                                {"SigmaSpace", 150},
                                {"BorderType", 4}};

    MultiImageFilter multiImageFilter{filterConfig7};
    cv::Mat image{cv::imread("1.png")};
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

    cv::Mat image2{};
    cv::Mat image3{};
    //image.copyTo(image2);
    //image.copyTo(image3);
    image2 = image.clone();
    //image3 = image.clone();


    multiImageFilter.process(image2);
    cv::bilateralFilter(image, image3, 10, 150, 150,4);

    cv::imshow("Before", image);
    cv::imshow("After", image2);
    cv::imshow("bilateralFilter", image3);
    cv::waitKey(0);

    return 0;
}
