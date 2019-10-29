#ifndef BASEFILTER_H
#define BASEFILTER_H

#include "../../../block/src/block.h"
#include <opencv2/imgproc.hpp>

class BaseFilter
{
 public:
  BaseFilter();
  virtual ~BaseFilter();

  virtual void process(cv::Mat &a_src) = 0;
};

#endif // BASEFILTER_H
