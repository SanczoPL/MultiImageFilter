#include "resize.h"
#include <QJsonObject>

constexpr auto WIDTH{ "Width" };
constexpr auto HEIGHT{ "Height" };

Filter::Resize::Resize(QJsonObject const &a_config)
  : m_width{ a_config[WIDTH].toInt() }
  , m_height{ a_config[HEIGHT].toInt() }
{
}

void Filter::Resize::process(cv::Mat &a_src)
{
  cv::resize(a_src, a_src, cv::Size(m_width, m_height));
}
