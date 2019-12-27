#ifndef BLUR_H
#define BLUR_H

#include "basefilter.h"


/* Paste in configuration:
[{	
  "name": "Blur_KernelSizeX",
  "min": 1,
  "max": 23,
  "isOdd": true
},{
  "name": "Blur_KernelSizeY",
  "min": 1,
  "max": 23,
  "isOdd": true
},{
  "name": "Blur_BorderType",
  "min": 1,
  "max": 2
}],
*/

class QJsonObject;

namespace Filter {
class Blur : public BaseFilter {
 public:
  Blur(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  int const m_kernelSizeX;
  int const m_kernelSizeY;
  int const m_borderType;
};
} // namespace Filter

#endif // BLUR_H
