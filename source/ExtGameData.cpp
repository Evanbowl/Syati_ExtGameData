#include "ModuleData_ExtGameData.h"
#include "ExtGameDataUtil.h"

namespace {
    ExtGameDataHolder* extCreateChunks(ExtGameDataHolder *pHolder) {
        for (s32 i = 1; i < cExtSaveChunkCount; i++) {
            BinaryDataChunkBase *pChunk = cExtSaveChunkCreateTable[i]();

            if (pChunk) {
                *(u32 *)(pHolder + sizeof(GameDataHolder) + 4 * (i - 1)) = (u32)pChunk;
                pHolder->mBinaryDataChunkHolder->addChunk(pChunk);
            }
        }

        return pHolder;
    }
}

kmWrite16(0x804D483A, 6 + cExtSaveChunkCount);
kmBranch(0x804D48BC, extCreateChunks);

kmWrite16(0x804DF00E, sizeof(ExtGameDataHolder) + 0x10); // Unsure what the extra 16 bytes are but if I don't add it this crashes lmao