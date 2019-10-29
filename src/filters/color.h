#ifndef COLOR_H
#define COLOR_H

#include "basefilter.h"

class QJsonObject;

namespace Filter {
class Color : public BaseFilter {
 public:
  Color(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  int const m_colorCode;
};
} // namespace Filter

#endif // COLOR_H
