#include "morphologyoperation.h"
#include <QJsonObject>

constexpr auto MORPH_OPERATOR{ "MorphOperator" }; // MorphTypes
constexpr auto MORPH_SIZE{ "MorphSize" };
constexpr auto MORPH_ELEMENT{ "MorphElement" }; // MorphShapes

Filter::MorphologyOperation::MorphologyOperation(QJsonObject const &a_config)
  : m_morphOperator{ a_config[MORPH_OPERATOR].toInt() }
  , m_morphSize{ a_config[MORPH_SIZE].toInt() }
  , m_morphElement{ a_config[MORPH_ELEMENT].toInt() }
{
}

void Filter::MorphologyOperation::process(cv::Mat &a_src)
{
  cv::Mat m_Element = cv::getStructuringElement(m_morphElement, cv::Size(2 * m_morphSize + 1, 2 * m_morphSize + 1),
                                                cv::Point(m_morphSize, m_morphSize));
  morphologyEx(a_src, a_src, m_morphOperator, m_Element);
}
