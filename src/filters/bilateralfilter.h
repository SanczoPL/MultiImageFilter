#ifndef BILATERALFILTER_H
#define BILATERALFILTER_H

#include "basefilter.h"

class QJsonObject;

namespace Filter {
class BilateralFilter : public BaseFilter {
 public:
  BilateralFilter(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  int const m_diameter;
  double const m_sigmaColor;
  double const m_sigmaSpace;
  int const m_borderType;
};
} // namespace Filter

#endif // BILATERALFILTER_H
