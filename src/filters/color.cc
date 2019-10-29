#include "color.h"
#include <QJsonObject>

constexpr auto COLOR_CODE{ "ColorCode" };

Filter::Color::Color(QJsonObject const &a_config)
  : m_colorCode{ a_config[COLOR_CODE].toInt() }
{
}

void Filter::Color::process(cv::Mat &a_src)
{
  cv::cvtColor(a_src, a_src, m_colorCode);
}
