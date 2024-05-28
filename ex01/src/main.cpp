#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <ostream>

int main(void)
{
	Data *data = new Data();
	data->setvalue(2);

	std::cout << "old data: " << *data << ", pointer: " << data << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	std::cout << "raw: " << raw << std::endl;
	Data *ddata = Serializer::deserialize(raw);
	std::cout << "new data: " << *ddata << ", pointer: " << ddata << std::endl;
	delete data;
}
