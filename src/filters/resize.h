#ifndef RESIZE_H
#define RESIZE_H

#include "basefilter.h"

class QJsonObject;

namespace Filter {
class Resize : public BaseFilter {
 public:
  Resize(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  int const m_width;
  int const m_height;
};
} // namespace Filter

#endif // RESIZE_H
