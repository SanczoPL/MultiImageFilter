#ifndef NONE_H
#define NONE_H

#include "basefilter.h"

class QJsonObject;

namespace Filter {
class None : public BaseFilter {
 public:
	None();

	void process(cv::Mat &a_src);

 private:
};
} // namespace Filter

#endif // NONE_H
