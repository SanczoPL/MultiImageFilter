#ifndef SOBEL_H
#define SOBEL_H

#include "basefilter.h"

class QJsonObject;



/* Paste in configuration:
[{	
  "name": "Sobel_OrderDerivativeX",
  "min": 1,
  "max": 2
},{
  "name": "Sobel_OrderDerivativeY",
  "min": 1,
  "max": 2
},{
  "name": "Sobel_KernelSize",
  "min": 1,
  "max": 7,
  "isOdd": true
},{
  "name": "Sobel_BorderType",
  "min": 1,
  "max": 2
}],
*/

namespace Filter {
class Sobel : public BaseFilter {
 public:
  Sobel(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  int const m_orderDerivativeX;
  int const m_orderDerivativeY;
  int const m_kernelSize;
  int const m_borderType;
  double m_scale;
  double m_delta;
};
} // namespace Filter

#endif // SOBEL_H
