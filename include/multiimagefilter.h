#ifndef MULTIIMAGEFILTER_H
#define MULTIIMAGEFILTER_H

#include <opencv2/imgproc.hpp>
#include <QVector>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

class BaseFilter;
class QJsonArray;
namespace cv
{
class Mat;
class TickMeter;
} // namespace cv

class MultiImageFilter
{
 public:
  MultiImageFilter(QJsonObject const &m_filter);
  ~MultiImageFilter();

  void configure(QJsonObject const &m_filter);
  void process(cv::Mat &a_image);
  double getElapsedTimeSubtractor();

 private:
  BaseFilter * m_baseFilter{};
  cv::TickMeter m_timer;
};

#endif // MULTIIMAGEFILTER_H
