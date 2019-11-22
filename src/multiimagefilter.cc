#include "../../MultiImageFilter/include/multiimagefilter.h"
#include "../../IncludeSpdlog/spdlog.h"

#include "filter.h"

constexpr auto FILTER_NAME{ "Name" };

MultiImageFilter::MultiImageFilter(QJsonObject const &m_filter)
{
  configure(m_filter);
}

MultiImageFilter::~MultiImageFilter()
{
  delete m_baseFilter;
}

void MultiImageFilter::configure(QJsonObject const &m_filter)
{
  delete m_baseFilter;
  m_timer.reset();

  auto const NAME_STRING{ m_filter[FILTER_NAME].toString().toStdString() };
  auto const NAME_SID{ SID(NAME_STRING.c_str()) };

  switch (NAME_SID)
  {
    case SID("GaussianBlur"): m_baseFilter = new Filter::GaussianBlur{ m_filter }; break;
    case SID("Color"): m_baseFilter = new Filter::Color{ m_filter }; break;
    case SID("Resize"): m_baseFilter = new Filter::Resize{ m_filter }; break;
    case SID("Threshold"): m_baseFilter = new Filter::Threshold{ m_filter }; break;
    case SID("MedianBlur"): m_baseFilter = new Filter::MedianBlur{ m_filter }; break;
    case SID("MorphologyOperation"): m_baseFilter = new Filter::MorphologyOperation{ m_filter }; break;
    case SID("None"): m_baseFilter = new Filter::None{}; break;
    default: H_Logger->error("Unsupported filter type: {}", NAME_STRING); break;
  }
}

void MultiImageFilter::process(cv::Mat &a_image)
{
  m_timer.start();
  m_baseFilter->process(a_image);
  m_timer.stop();
}
double MultiImageFilter::getElapsedTimeSubtractor()
{
  return m_timer.getTimeMilli();
}
