#ifndef MORPHOLOGY_OPERATION_H
#define MORPHOLOGY_OPERATION_H

#include "basefilter.h"

class QJsonObject;

namespace Filter {
class MorphologyOperation : public BaseFilter {
 public:
  MorphologyOperation(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  cv::Mat const m_Element;
  int const m_morphOperator;
  int const m_morphSize;
  int const m_morphElement;
};
} // namespace Filter

#endif // MORPHOLOGY_OPERATION_H
