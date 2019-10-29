#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "basefilter.h"

class QJsonObject;

namespace Filter
{
class Threshold : public BaseFilter
{
 public:
  Threshold(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  qint32 m_decisionThreshold;
  qint32 m_thresholdTypes;
};
} // namespace Filter

#endif // THRESHOLD_H
