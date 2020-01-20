#ifndef RENGINE_H
#define RENGINE_H

#include "Canvas.h"
#include "Pixel.h"
#include "PixelBuffer.h"

#include <vector>

namespace cobre
{
    namespace core
    {
        class Rengine
        {
            private:
                PixelBuffer m_pixels;
                Canvas m_frame;

            public:
                Rengine(std::size_t frameX, std::size_t frameY):
                    m_frame{frameX, frameY}
                {
                }
                void render();

                void resize(std::size_t x, std::size_t y);
                size2d_t size() {return m_frame.getSize();}

                friend std::ostream& operator<<(std::ostream &out, Rengine &rengine);
                friend void operator<<(Rengine &rengine, PixelBuffer &buffer);
                //friend void operator<<(Rengine &rengine, std::vector<Pixel>);
        };
    }
}	

#endif
