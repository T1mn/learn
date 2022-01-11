import numpy as np

convKernel = np.ones((3, 3))
beConvedFm = np.arange(25).reshape(5, 5)

def conv(kenel: np.ndarray, fm: np.ndarray, stride: int, pad: int) -> np.ndarray:
    # print(type(kenel))
    if pad:
        fm = np.pad(fm, (pad, pad), 'constant', constant_values=(0, 0))
    print(fm)
    kenelH = kenel.shape[0]
    kenelW = kenel.shape[1]
    fmH = fm.shape[0]
    fmW = fm.shape[1]
    if kenelH > fmH or kenelW > fmW or (fmH - kenelH) % stride % 1 != 0 or (fmW - kenelW)/stride % 1 != 0:
        return
    newFmH = (int)((fmH - kenelH+2*pad)/stride + 1)
    newFmW = (int)((fmW - kenelW+2*pad)/stride + 1)
    curRow = 0
    curCol = 0
    newSize = int(newFmH * newFmW)
    newFm = np.zeros(newSize)
    for i in range (newSize):
        # print(curRow)
        beConvArray = fm[curRow:curRow+kenelH, curCol:curCol+kenelW]
        newFm[i] = (kenel * beConvArray).sum()
        if (curCol + stride + kenelW) > fmW:
            curRow += stride
            curCol = 0
        else:
            curCol += stride
    newFm = newFm.reshape(newFmH, newFmW)
    return newFm

newFm = conv(convKernel, beConvedFm, 1, 1)
print(newFm)