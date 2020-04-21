#include "medianblur.h"
#include <QJsonObject>

constexpr auto KERNEL_SIZE{ "KernelSize" };

Filter::MedianBlur::MedianBlur(QJsonObject const &a_config)
  : m_kernelSize{ a_config[KERNEL_SIZE].toInt() }
{
}

void Filter::MedianBlur::process(cv::Mat &a_src)
{
  cv::medianBlur(a_src, a_src, m_kernelSize);
}
