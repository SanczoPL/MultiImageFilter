#ifndef MEDIANBLUR_H
#define MEDIANBLUR_H

#include "basefilter.h"

class QJsonObject;

namespace Filter {
class MedianBlur : public BaseFilter {
 public:
  MedianBlur(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  int const m_kernelSize;
};
} // namespace Filter

#endif // MEDIANBLUR_H
