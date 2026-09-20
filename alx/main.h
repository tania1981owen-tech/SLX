#ifndef ALX_VERSION
#define ALX_VERSION

#include <Windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <vector>
#include <algorithm>

#include "rlua.h"

#define ALXERR 200
#define ALXRESTART 100

extern DWORD ROBLOX_BASE;
extern DWORD ALX_BASE;
extern DWORD GameInstance;
extern DWORD LocalPlayer;
extern std::string LocalPlayerName;
extern RLua* rLua;

typedef struct PEntry {
    std::string* pName;
    float pDistance;
};

void Initiate();
void CreateConsole();
BOOLEAN DoesConsoleExist();
int main();
void HandleCommand(std::string command);
std::vector<DWORD> GetPlayersFromMessage(
    DWORD gameInstance,
    std::vector<std::string> argList
);

// YAML
#include <yaml-cpp/yaml.h>

void SaveConfigurationFile(
    const std::string& filename,
    const YAML::Node& config
);

void LoadConfigurationFile(
    const std::string& filename,
    YAML::Node& config
);

// Совместимость со старым кодом проекта.
// Старый проект использует:
//     ConfigFile != 0
//
// Важно: эти функции находятся ВНУТРИ include guard,
// поэтому они больше не объявляются повторно.
inline bool operator!=(const YAML::Node& node, int value)
{
    if (value == 0)
    {
        return node.IsDefined() && !node.IsNull();
    }

    return true;
}

inline bool operator!=(int value, const YAML::Node& node)
{
    return node != value;
}

#endif
