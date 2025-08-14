#include "ModuleData_ExtGameData.h"
#include "ExtGameDataUtil.h"

namespace {
    GameDataHolder* extCreateChunks(GameDataHolder *pHolder) {
        for (s32 i = 1; i < cExtSaveChunkCount; i++) {
            BinaryDataChunkBase *pChunk = cExtSaveChunkCreateTable[i]();
            sExtSaveChunkTable[i] = pChunk;

            if (pChunk) {
                pHolder->mBinaryDataChunkHolder->addChunk(pChunk);
            }
        }

        return pHolder;
    }
}

kmWrite16(0x804D483A, 6 + cExtSaveChunkCount);
kmBranch(0x804D48BC, extCreateChunks);