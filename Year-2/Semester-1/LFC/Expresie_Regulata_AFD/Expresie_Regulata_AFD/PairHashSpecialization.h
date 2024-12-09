#pragma once
#include <string>
#include <functional>
namespace custom
{
	struct hash_pair {
		template <class T1, class T2>
		size_t operator()(const std::pair<T1, T2>& p) const
		{
			auto hash1 = std::hash<T1>{}(p.first);
			auto hash2 = std::hash<T2>{}(p.second);
			return hash1 ^ hash2;
		}
	};
	struct MyKeyEqual
	{
		template <class T1, class T2>
		bool operator()(const std::pair<T1, T2>& pair1, const std::pair<T1, T2>& pair2)
			const
		{
			return (pair1.first == pair2.first) && (pair1.second == pair2.second);
		}
	};
};