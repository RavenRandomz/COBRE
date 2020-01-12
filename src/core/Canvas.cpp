#include "Canvas.h"

#include <cassert>
#include <iostream>
#include <stddef.h>

namespace cobre
{
	namespace core
	{
		std::string& Canvas::operator[](int index)
		{
			return m_frame[index];
		}

		char& Canvas::operator()(std::size_t x, std::size_t y)
		{
			assert(x < m_size.x && y < m_size.y && "Out of bounds access"); 

			//The y axis numbers ascend top to bottom. graphicY ascends bottom to top
			std::size_t graphicY(m_size.y - y);
			return m_frame[graphicY][x];
		}

		void Canvas::clear()
		{
			std::string blank(m_size.x, m_background);

			for(std::size_t i{0}; i < m_size.y;i++)
			{
				m_frame[i] = blank;
			}
		}	

		std::ostream& operator<< (std::ostream &out, const Canvas &canvas)
		{
			for(std::size_t i{0}; i < canvas.m_size.y; i++)
			{
				out << canvas.m_frame[i] << '\n';
			}
			return out;	
		}
		
		void operator<< (Canvas &canvas, const Pixel p)
		{
			canvas(p.m_pos.x, p.m_pos.y) = p.m_texture;
		}



	}
}
