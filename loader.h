#include "windows.h"

#include "xorstr.h"
#include "VMProtectSDK.h"

#pragma comment( lib, "VMProtectSDK64.lib" )

#pragma pack( push, 1 )
struct loader_challenge
{
	uint64_t	magic1;						// check 1
	uint32_t	game_id;					//
	uint32_t	language_id;				//
	int64_t		create_time;				// check 3
	uint64_t	magic2;						// check 2
	uint64_t	random;						//
	uint8_t		ini_path[256];				//
	uint32_t	reseller_id;				//
	uint64_t	mac_hash;					// not used
	uint64_t	serial_hash;				// not used
	uint64_t	checksum;					// not used
};
#pragma pack( pop )

constexpr uint64_t loader_data_offset = 0x117;
constexpr uint64_t loader_magic_1 = 0x12398DFF8123A77C;
constexpr uint64_t loader_magic_2 = 0xADD7123FCC163203;
constexpr uint64_t loader_time_encryption_key = 0x24922073969;

enum E_LOAD_CHALLENGE_CODE : uint32_t
{
	failure_file_not_opened = 700,
	failure_file_not_mapped = 701,
	failure_struct_magic_invalid = 702,
	failure_struct_time_invalid = 703,
};

// some developers have different xorstr defines?
//

#define xorstr_

__declspec(noinline) bool verify_loader();