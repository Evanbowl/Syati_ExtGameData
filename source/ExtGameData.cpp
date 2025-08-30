#include "ModuleData_ExtGameData.h"
#include "ExtGameDataUtil.h"

namespace {
    ExtGameDataHolder* extCreateChunks(ExtGameDataHolder *pHolder) {
        for (s32 i = 1; i < cExtSaveChunkCount; i++) {
            BinaryDataChunkBase *pChunk = cExtSaveChunkCreateTable[i]();

            if (pChunk) {
                // TODO Find a better way to do this
                u32 memberOffset = (u32)pHolder + sizeof(GameDataHolder) + 4 * (i - 1);
                *(u32 *)memberOffset = (u32)pChunk;

                pHolder->mBinaryDataChunkHolder->addChunk(pChunk);
            }
        }

        return pHolder;
    }
}

kmWrite16(0x804D483A, 6 + cExtSaveChunkCount);
kmBranch(0x804D48BC, extCreateChunks);

kmWrite16(0x804DF00E, sizeof(ExtGameDataHolder));