#include <iostream>
#include <vector>

#include <map>
#include <unordered_map>

struct CityRecord
{
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;

	bool operator<(const CityRecord& other) const
	{
		return Population < other.Population;
	}
};

namespace std
{
	template<>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& key)
		{
			return hash<std::string>()(key.Name);
		}
	};
}

int main()
{
	std::map<std::string, CityRecord> cityMap;
	cityMap["Melbourne"] = CityRecord{ "Melbourne", 5000000, 2.4, 9.4};
	cityMap["Lol-town"] = CityRecord{ "Lol-town", 5000000, 2.4, 9.4};
	cityMap["Parise"] = CityRecord{ "Parise", 5000000, 2.4, 9.4};
	cityMap["Berlin"] = CityRecord{ "Berlin", 5000000, 2.4, 9.4};
	cityMap["London"] = CityRecord{ "London", 5000000, 2.4, 9.4};

	std::map<CityRecord, uint32_t> cityFounded;
	cityFounded[cityMap["Melbourne"] = CityRecord{ "Melbourne", 5000000, 2.4, 9.4 }];

	cityMap.erase("Parise");
	const auto& cities = cityMap;
	if (cities.find("Berlin") != cities.end())
	{
		const CityRecord& berlinData = cities.at("Berlin");
		// berlinData.Name = "Berlin";
		// berlinData.Population = 5;
	}

	for (auto& [name, city] : cityMap)
	{
		std::cout << name << "\n Population : " << city.Population << std::endl;
		cityFounded[city];
	}

	for (auto& [city , founded] : cityFounded)
	{
		std::cout << city.Name << "\n Population : " << city.Population << std::endl;
	}
}