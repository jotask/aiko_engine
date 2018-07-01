#include "camera.h"

#include "../constants.h"

namespace aiko
{

    static constexpr auto s_s = 1.0f;

    Camera::Camera()
        : m_pos(0.0f, 0.0f)
        , m_rotation(0.0f)
        , m_zoom(1.0f)
        , m_bound(WIDTH * s_s, HEIGHT * s_s)
        , m_view(sf::FloatRect(m_pos.x, m_pos.y, m_bound.x, m_bound.y))
    {
        m_view.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
    }

    Camera::~Camera()
    {

    }


    void Camera::setZoom(const float z)
    {
        //m_zoom = z;
    }

    bool Camera::isOnCamera(const BodyEntity& entity) const
    {
        const auto bound = entity.m_shape.get()->getGlobalBounds();
        const auto our = Camera::getViewBounds(m_view);
        return bound.intersects(our);
    }

    void Camera::update(const TimeStamp& delta)
    {

    }

    void Camera::render(sf::RenderWindow& window)
    {
        m_view.move(0.0f, 0.0f);
        m_view.move(m_pos.x, m_pos.y);
        m_view.setRotation(m_rotation);
        m_view.zoom(m_zoom);

        window.setView(m_view);
    }

    sf::FloatRect Camera::getViewBounds(const sf::View &view)
    {
        sf::FloatRect rt;
        rt.left = view.getCenter().x - view.getSize().x / 2.f;
        rt.top = view.getCenter().y - view.getSize().y / 2.f;
        rt.width = view.getSize().x;
        rt.height = view.getSize().y;
        return rt;
    }

}