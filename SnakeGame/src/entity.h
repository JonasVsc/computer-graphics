#ifndef __ENTITY_H__
#define __ENTITY_H__


class entity
{
public:
	entity();

	void set_shape();
	void set_color();
	void set_texture();


private:
	const char* m_name;
};



#endif