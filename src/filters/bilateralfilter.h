#ifndef BILATERALFILTER_H
#define BILATERALFILTER_H

#include "basefilter.h"

/* Paste in configuration:
[{
  "name": "BilateralFilter_Diameter",
  "min": 1,
  "max": 5
},{
  "name": "BilateralFilter_SigmaColor",
  "min": 1,
  "max": 1000,
  "isDouble": 100
},{
  "name": "BilateralFilter_SigmaSpace",
  "min": 1,
  "max": 1000,
  "isDouble": 100
},{
  "name": "BilateralFilter_BorderType",
  "min": 1,
  "max": 2
}],
*/

class QJsonObject;

namespace Filter
{
class BilateralFilter : public BaseFilter
{
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
