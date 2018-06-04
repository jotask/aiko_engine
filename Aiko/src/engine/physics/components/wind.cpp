#include "wind.h"

#include <Box2D/Box2D.h>
#include "../../utils.h"

namespace aiko
{
    namespace physics
    {

        Wind::Wind()
            : PhysicsComponent(false)
            , pn(seed)
            , m_delta(0.0f, 0.0f, 0.0f)
        {

        }

        Wind::~Wind()
        {

        }

        void Wind::update(const TimeStamp& delta)
        {

            m_delta += sf::Vector3f(delta.delta, delta.delta, delta.delta);

            //double noise = pn.noise(0.45, 0.8, 0.55);

            auto tmp1 = Utils::map<double>(pn.noise(m_delta.x, m_delta.y, m_delta.z), 0.0, 1.0, -1.0, 1.0);
            auto tmp2 = Utils::map<double>(pn.noise(m_delta.z, m_delta.y, m_delta.x), 0.0, 1.0, -1.0, 1.0);

            b2Vec2 gravity(static_cast<float32>(tmp1), static_cast<float32>(tmp2));

            static constexpr auto g = 9.98f;

            auto& m_gravity = m_physics.getGravity();
            m_gravity.x = gravity.x * g;
            m_gravity.y = gravity.y * g;

            auto& m_world = m_physics.getWorld();
            m_world.SetGravity(m_gravity);

        }

        void Wind::render(sf::RenderWindow& window)
        {

            if (m_drawDebug == false) return;

            static constexpr bool drawBounds = true;
            static constexpr bool drawLines = true;
            static constexpr bool drawDebug = true;

            const auto windowSize = window.getSize();

            const auto manyCubes = sf::Vector2u(1u, 1u);

            const auto cubeSize = sf::Vector2f(
                100.0f, 100.0f//static_cast<float>(windowSize.x) / static_cast<float>(manyCubes.x) ,
                //static_cast<float>(windowSize.y) / static_cast<float>(manyCubes.y)
            );

            static constexpr auto Many = 4u;
            const auto manies = sf::Vector2u(Many, Many);

            for (auto i = 0u; i < manies.x; ++i) for (auto j = 0u; j < manies.y; ++j)
            {

                // initialize
                auto pos = sf::Vector2f(0.0f, 0.0f);
                auto siz = sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));

                // update
                {

                    // width / many
                    siz.x = static_cast<float>(window.getSize().x / static_cast<float>(manies.x));
                    siz.y = static_cast<float>(window.getSize().y / static_cast<float>(manies.y));

                    pos.x += siz.x;
                    pos.y += siz.y;
                }

                // drawing
                if (drawBounds)
                {
                    float x = pos.x * i;
                    float y = pos.y * j;
                    float w = siz.x;
                    float h = siz.y;

                    sf::RectangleShape shape;
                    const auto color = Utils::randomColor();
                    shape.setFillColor(sf::Color::Transparent);
                    shape.setOutlineThickness(3.0f);
                    shape.setOutlineColor(Utils::randomColor());
                    static constexpr auto scale = 1.0f;
                    shape.setPosition(sf::Vector2f(x + shape.getOutlineThickness() * scale, y + shape.getOutlineThickness() * scale));
                    shape.setSize(sf::Vector2f(w - shape.getOutlineThickness() * (scale * 2.0f), h - shape.getOutlineThickness() * (scale * 2.0f)));
                    window.draw(shape);
                }

                if (drawLines)
                {
                    float x = pos.x * i;
                    float y = pos.y * j;
                    float w = siz.x;
                    float h = siz.y;

                    sf::RectangleShape shape;
                    const auto color = Utils::randomColor();
                    shape.setFillColor(sf::Color::Transparent);
                    shape.setOutlineThickness(3.0f);
                    shape.setOutlineColor(Utils::randomColor());
                    static constexpr auto scale = 1.0f;
                    shape.setPosition(sf::Vector2f(x + shape.getOutlineThickness() * scale, y + shape.getOutlineThickness() * scale));
                    shape.setSize(sf::Vector2f(w - shape.getOutlineThickness() * (scale * 2.0f), h - shape.getOutlineThickness() * (scale * 2.0f)));
                    window.draw(shape);

                    auto one = sf::Vector2f(sf::Vector2f(x + shape.getOutlineThickness() * scale, y + shape.getOutlineThickness() * scale));
                    auto tmp_tmp = sf::Vector2f(w - shape.getOutlineThickness() * (scale * 2.0f), h - shape.getOutlineThickness() * (scale * 2.0f));
                    auto two = sf::Vector2f(one.x + tmp_tmp.x, one.y + tmp_tmp.y);

                    auto tmp1 = pn.noise(m_delta.x, m_delta.y, m_delta.z);
                    auto tmp2 = pn.noise(m_delta.z, m_delta.y, m_delta.x);

                    one.x += siz.x * 0.5f;
                    one.y += siz.y * 0.5f;

                    const auto radius = sf::Vector2f(80.0f, 80.0f);

                    two.x = one.x + (radius.x * static_cast<float>(std::sin(tmp1)));
                    two.y = one.y + (radius.y * static_cast<float>(std::cos(tmp2)));

                    sf::Vertex line[2];
                    line[0].position = one;
                    line[0].color = sf::Color::Red;
                    line[1].position = two;
                    line[1].color = Utils::randomColor();
                    window.draw(line, 2, sf::Lines);
                }
            }

            const sf::Vector2f size(cubeSize.x, cubeSize.y);

            //std::cout << "Size: " << 0 << std::endl;

            for (float x = 0.0f; x < windowSize.x; x += cubeSize.x)
            {
                for (float y = 0.0f; y < windowSize.y; y += cubeSize.y)
                {
                    if (false)
                    {
                        sf::RectangleShape shape;
                        const auto color = Utils::randomColor();
                        shape.setFillColor(sf::Color::Transparent);
                        shape.setOutlineThickness(3.0f);
                        shape.setOutlineColor(Utils::randomColor());
                        shape.setPosition(sf::Vector2f(x, y));
                        shape.setSize(size);
                        window.draw(shape);
                    }
                }
            }

            if (true) return;

            const auto separation = 100u;

            for (unsigned int i = 0; i < windowSize.x; i += separation)
            {
                for (unsigned int j = 0; j < windowSize.y; j += separation)
                {
                    if (drawDebug == true)
                    {

                    }
                    if (drawBounds == true)
                    {
                        float x = static_cast<float>(i * size.x);
                        float y = static_cast<float>(j * size.y);
                        float w = size.x * separation;
                        float h = size.y * separation;
                        sf::RectangleShape shape;
                        const auto color = Utils::randomColor();
                        shape.setFillColor(sf::Color::Transparent);
                        shape.setOutlineThickness(3.0f);
                        shape.setOutlineColor(Utils::randomColor());
                        shape.setPosition(sf::Vector2f(x, y));
                        shape.setSize(sf::Vector2f(w, h));
                        window.draw(shape);
                    }
                    if (drawLines == true)
                    {
                        float w = size.x * separation;
                        float h = size.y;
                        float x = static_cast<float>((i * size.x) /*+ ( w * 0.5f ) */);
                        float y = static_cast<float>((j * size.y) /*+ ( h * 0.5f ) */);
                        if (i != 0 && j != 0) return;
                        sf::Vertex line[2];
                        line[0].position = sf::Vector2f(x, y);
                        line[0].color = sf::Color::Red;
                        line[1].position = sf::Vector2f(x + w, y + h);
                        line[1].color = Utils::randomColor();
                        window.draw(line, 2, sf::Lines);
                    }
                }
            }
        }

    }
}