file(READ ${SOURCE_DIR}/retrieve_pastie.lua retrieve_pastie)
file(READ ${SOURCE_DIR}/save_pastie.lua save_pastie)
string(REGEX REPLACE "[ \t]*=[ \t]*" "=" retrieve_pastie "${retrieve_pastie}")
string(REGEX REPLACE "[ \t]*=[ \t]*" "=" save_pastie "${save_pastie}")
string(REGEX REPLACE ",[ \t]*" "," retrieve_pastie "${retrieve_pastie}")
string(REGEX REPLACE ",[ \t]*" "," save_pastie "${save_pastie}")
string(REGEX REPLACE "(^|\n)[ \t]+" "\\1" retrieve_pastie "${retrieve_pastie}")
string(REGEX REPLACE "(^|\n)[ \t]+" "\\1" save_pastie "${save_pastie}")
string(LENGTH "${retrieve_pastie}" retrieve_pastie_length)
string(LENGTH "${save_pastie}" save_pastie_length)

set(lua_scripts_for_redis_content "//File autogenerated by cmake, changes will be lost
#include <cstddef>
namespace kamokan {
extern const char g_save_script[] = R\"lua(${save_pastie})lua\";
extern const char g_load_script[] = R\"lua(${retrieve_pastie})lua\";
extern const std::size_t g_save_script_size = ${save_pastie_length};
extern const std::size_t g_load_script_size = ${retrieve_pastie_length};
} //namespace kamokan
")

file(WRITE
	include/lua_scripts_for_redis.cpp
	"${lua_scripts_for_redis_content}"
)

unset(lua_scripts_for_redis_content)
unset(save_pastie_length)
unset(retrieve_pastie_length)
unset(save_pastie)
unset(retrieve_pastie)
