#include "blur.h"
#include <QJsonObject>

constexpr auto KERNEL_SIZE_X{ "KernelSizeX" };
constexpr auto KERNEL_SIZE_Y{ "KernelSizeY" };
constexpr auto BORDER_TYPE{ "BorderType" };

Filter::Blur::Blur(QJsonObject const &a_config)
  : m_kernelSizeX{ a_config[KERNEL_SIZE_X].toInt() }
  , m_kernelSizeY{ a_config[KERNEL_SIZE_Y].toInt() }
  , m_borderType{ a_config[BORDER_TYPE].toInt() }
{
}

void Filter::Blur::process(cv::Mat &a_src)
{
  cv::blur(a_src,a_src,cv::Size(m_kernelSizeX, m_kernelSizeY),cv::Point(-1,-1),m_borderType);
}
