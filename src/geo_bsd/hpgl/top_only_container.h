#ifndef __TOP_ONLY_CONTAINER_H__5DF4F22D_2567_496B_89F5_FE3894D670F4
#define __TOP_ONLY_CONTAINER_H__5DF4F22D_2567_496B_89F5_FE3894D670F4

namespace hpgl
{
	template<typename T>
	class top_only_container_t
	{
		std::vector<T> m_data;
		size_t m_size;	
		T m_min_t;
		size_t m_min_idx;

		void find_min()
		{
			//pre:
			//	m_size == m_data.size()
			//	m_size > 0
			T min_t = m_data[0]; //valid if m_size > 0;
			size_t min_idx = 0;
			size_t current_size = m_data.size();
			for (size_t i = 1; i < current_size; ++i)
			{
				if (min_t > m_data[i])
				{					
					min_t = m_data[i];
					min_idx = 0;
				}
			}
			m_min_t = min_t;
			m_min_idx = min_idx;
			//post:
			//	m_mint_t - minimum element in vector
			//	m_min_idx - index of min			
		}
	public:
		top_only_container_t(size_t size)
			: m_size(size)
		{
			m_data.reserve(size);
		}

		void add(T t)
		{
			//pre:
			size_t current_size = m_data.size();
			if (current_size >= m_size)
			{
				if (t > m_min_t)
				{
					m_data[m_min_idx] = t;
					find_min();
				}
			}
			else
			{
				m_data.push_back(t);
				find_min();
			}
			//post:
		}

		const std::vector<T> & get_them()
		{
			return m_data;
		}
	};
}

#endif //__TOP_ONLY_CONTAINER_H__5DF4F22D_2567_496B_89F5_FE3894D670F4