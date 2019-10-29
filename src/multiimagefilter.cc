#include "../../multiimagefilter/include/multiimagefilter.h"
#include "../../includeSpdlog/include/includeSpdlog.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include "filter.h"

constexpr auto FILTER_NAME{ "Name" };

MultiImageFilter::MultiImageFilter(QJsonArray const &a_filtersConfiguration)
{
  configure(a_filtersConfiguration);
}

MultiImageFilter::~MultiImageFilter()
{
  for (auto filter : m_filters)
  {
    delete filter;
  }
}

void MultiImageFilter::configure(QJsonArray const &a_filtersConfiguration)
{
  for (auto filter : m_filters)
  {
    delete filter;
  }
  m_timer.reset();
  m_filters.clear();

  for (auto const &FILTER_CONFIG : a_filtersConfiguration)
  {
    auto const NAME_STRING{ FILTER_CONFIG[FILTER_NAME].toString().toStdString() };
    auto const NAME_SID{ SID(NAME_STRING.c_str()) };

    switch (NAME_SID)
    {
      case SID("GaussianBlur"): m_filters.push_back(new Filter::GaussianBlur{ FILTER_CONFIG.toObject() }); break;
      case SID("Color"): m_filters.push_back(new Filter::Color{ FILTER_CONFIG.toObject() }); break;
      case SID("Resize"): m_filters.push_back(new Filter::Resize{ FILTER_CONFIG.toObject() }); break;
      case SID("Threshold"): m_filters.push_back(new Filter::Threshold{ FILTER_CONFIG.toObject() }); break;
      case SID("MedianBlur"): m_filters.push_back(new Filter::MedianBlur{ FILTER_CONFIG.toObject() }); break;
      case SID("MorphologyOperation"):
        m_filters.push_back(new Filter::MorphologyOperation{ FILTER_CONFIG.toObject() });
        break;
      case SID("None"): m_filters.push_back(new Filter::None{}); break;
      default: H_Logger->error("Unsupported filter type: {}", NAME_STRING); break;
    }
  }
}

void MultiImageFilter::process(cv::Mat &a_image)
{
  m_timer.start();
  for (auto filter : m_filters)
  {
    filter->process(a_image);
  }
  m_timer.stop();
}
double MultiImageFilter::getElapsedTimeSubtractor()
{
  return m_timer.getTimeMilli();
}
