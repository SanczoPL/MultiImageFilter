#ifndef MULTIIMAGEFILTER_H
#define MULTIIMAGEFILTER_H

#include <opencv2/imgproc.hpp>
#include <QVector>

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
  MultiImageFilter(QJsonArray const &a_filtersConfiguration);
  ~MultiImageFilter();

  void configure(QJsonArray const &a_filtersConfiguration);
  void process(cv::Mat &a_image);
  double getElapsedTimeSubtractor();

 private:
  QVector<BaseFilter *> m_filters{};
  cv::TickMeter m_timer;
};

#endif // MULTIIMAGEFILTER_H
