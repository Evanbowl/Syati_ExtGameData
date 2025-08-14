#include "ExtGameDataUtil.h"
#include "ModuleData_ExtGameData.h"

namespace ExtGameDataUtil {
    BinaryDataChunkBase* getChunk(u32 signature) {
        for (s32 i = 1; i < cExtSaveChunkCount; i++) {
            BinaryDataChunkBase *pChunk = sExtSaveChunkTable[i];

            if (pChunk && pChunk->getSignature() == signature) {
                return pChunk;
            }
        }

        return NULL;
    }
}