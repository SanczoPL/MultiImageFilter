#include "threshold.h"
#include <QJsonObject>

constexpr auto DECISIONTHRESHOLD{ "DecisionThreshold" };
constexpr auto THRESHOLDTYPES{ "ThresholdTypes" };

Filter::Threshold::Threshold(QJsonObject const &a_config)
  : m_decisionThreshold{ a_config[DECISIONTHRESHOLD].toInt() }
  , m_thresholdTypes{ a_config[THRESHOLDTYPES].toInt() }
{
}

void Filter::Threshold::process(cv::Mat &a_src)
{
  cv::threshold(a_src, a_src, m_decisionThreshold, 255, m_thresholdTypes);
}
