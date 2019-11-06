#pragma once
#include <cstdint>
#include <mutex>
#include "vector.hpp"

std::mutex entity_mutex;

struct mono_string
{
	char pad_0[ 0x10 ];
	std::uint32_t size;
	wchar_t buffer;
};

struct item_container
{
	char pad_0[ 0x30 ];
	void* contents;
};

struct player_inventory
{
	char pad_0[ 0x20 ];
	item_container* container_main;
	item_container* container_belt;
	item_container* container_wear;
};

struct player_input
{
	char pad_0[ 0x3c ];
	geo::vec3_t body_angles;
};

struct player_model
{
	char pad_0[ 0x1d4 ];
	bool is_visible;
	char pad_1[ 0xc ];
	bool is_local_player;
};

struct unity_transform
{
	char pad_0[ 0x10 ];
	void* transform;
};

struct model_transforms
{
	char pad_0[ 0x190 ];
	unity_transform* neck;
	unity_transform* head;
};

struct model
{
	char pad_0[ 0x28 ];
	unity_transform* head_bone_transform;
	char pad_1[ 0x10 ];
	model_transforms* transforms;
};

struct base_collision
{
	char pad_0[ 0x20 ];
	model* model;
};

struct base_player
{
	char pad_0[ 0xb0 ];
	model* model;
	char pad_1[ 0x13c ];
	float health;
	char pad_2[ 0x298 ];
	player_inventory* inventory;
	char pad_3[ 0x10 ];
	player_input* input;
	char pad_4[ 0x8 ];
	base_collision* collision;
	char pad_5[ 0x28 ];
	mono_string* display_name;
	char pad_6[ 0x30 ];
	player_model* player_model;
	char pad_7[ 0x41 ];
	bool sleeping;
	char pad_8[ 0x3e ];
	std::uint32_t team;
};

struct unk2
{
	char pad_0[ 0x28 ];
	base_player* player;
};

struct game_object
{
	char pad_0[ 0x18 ];
	unk2* unk;
};

struct buffer_list
{
	char pad_0[ 0x10 ];
	std::uint32_t size;
	void* buffer;
};

struct dictionary
{
	char pad_0[ 0x20 ];
	buffer_list* keys;
	buffer_list* values;
};

struct entity_realm
{
	char pad_0[ 0x10 ];
	dictionary* list;
};