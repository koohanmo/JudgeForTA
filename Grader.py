import os
import subprocess
import xlsxwriter

codeDir ="codes/"
testSetDir = "testSet/"
resultSetDir= "resultLog/"

class gradingResult:
    def __init__(self, id):
        self.id=id
        self.log=""
        self.result=""

    def setResult(self,result):
        self.result=result

    def setLog(self,log):
        self.log = log

    def appendLog(self,apLog):
        self.log = self.log+apLog+"\n"

    def getTotalResult(self):
        return self.id,self.result,self.log

def compileCode(cppfileName):
    if(cppfileName.find('.cpp')==-1) : return False
    # g++ Main.cc - o Main - O2 - Wall - lm - -static - std = c + +11 - DONLINE_JUDGE
    commandStr = "g++ " +cppfileName + " -o " +cppfileName[:-4] + " -O2 -std=c++11"
    output = subprocess.Popen([commandStr], stderr=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)

    #To file
    outputStr = output.stdout.read()
    outputErr = output.stderr.read()

    if (outputErr.decode('utf-8').find("error") != -1): return False,outputErr.decode('utf-8')
    return True, ""

def getFiles(TestPath):
    os.chdir(TestPath)
    codeFiles = []
    inputFiles = []
    outputFiles = []

    #Check files
    for files in os.listdir(TestPath+'/'+codeDir):
        if files.find(".cpp")!= -1:
            codeFiles.append(files)

    for files in os.listdir(TestPath+'/'+testSetDir):
        if files.find("input")!=-1 and files.find(".txt")!=-1:
            inputFiles.append(files)
        elif files.find("output")!=-1 and files.find(".txt")!=-1:
            outputFiles.append(files)


    codeFiles.sort()
    inputFiles.sort()
    outputFiles.sort()

    print("채점 대상 코드 : {0}".format(len(codeFiles)))
    print("채점 케이스 : {0}".format(len(inputFiles)))

    if len(inputFiles) != len(outputFiles):
        print("채점 데이터의 수가 맞지 않습니다.(input.txt의 수와 output.txt의 수가 일치하지 않습니다.)")
        return

    return codeFiles,inputFiles,outputFiles

def compareInputNOutput(input,output):
    with open(input) as inputTXT, open(output) as outputTXT:
        inputStrs= inputTXT.readlines()
        outputStrs = outputTXT.readlines()
        if inputStrs[-1]=='\n' or inputStrs[-1]=='':
            inputStrs=inputStrs[:-1]
        if len(inputStrs) != len(outputStrs):
            return False;
        for x in range(len(outputStrs)):
            if inputStrs[x].strip() != outputStrs[x].strip():
                #print(inputStrs[x].strip(), outputStrs[x].strip())
                return False
        return True;


def txtToStr(filename):
    with open(filename) as f:
        str=f.readlines()
        return "".join(x for x in str)

def excuteCode(command,
                inputFileName,
                outputFileName,
                resultFileName,
                resultErrFileName,
                maxTime=1):


    print("statr process : %s"%command)
    with open(inputFileName,'r') as inputTxt ,\
            open(resultFileName,'w+') as resultFile,\
            open(resultErrFileName,'w+') as errFile:
        try:

            p=subprocess.run([command],
                           stdin=inputTxt,
                           stdout=resultFile,
                           stderr=errFile,
                           timeout=int(maxTime))
            # print("stdout : ",p.stdout)
            # print("stderr : ",p.stderr)
            #print("returncode :",p.returncode)
            if p.returncode !=0:
                print("RuntimeError")
                return "RuntimeError"

        except subprocess.TimeoutExpired:
            print("Timeout")
            return "Timeout"
        except:
            print("Error")
            return "Error"

    isPass = compareInputNOutput(outputFileName, resultFileName)
    if isPass:
        return "Pass"
    else:
        return "Wrong Answer"




def txtFileToStrList(txt):
    ret=""
    with open(txt,mode='r') as f:
        ret = f.readlines()
    return ret

def grading(codeFiles,inputFiles,outputFiles):
    result=[]
    for cppcode in codeFiles:
        curResult = gradingResult(cppcode[:-4])
        result.append(curResult)

        #print("Start Compile %s...."%cppcode)
        compileResult, errLog = compileCode(cppfileName=codeDir+cppcode)
        if compileResult ==False:
            print("%s : CompileError"%cppcode)
            curResult.setResult("ComfileError")
            curResult.appendLog(errLog)
            continue;
        else :
            curResult.appendLog("CompilePass")

        #print("%s : Start Compare input && output"%cppcode)
        for x in range(len(inputFiles)):
            projectPath = os.path.abspath(".") + "/";

            inputPath = projectPath +testSetDir+ inputFiles[x]
            outputPath = projectPath +testSetDir+ outputFiles[x]

            resultDir = projectPath+ resultSetDir + cppcode[:-4]
            os.makedirs(resultDir, exist_ok=True)

            resultPath = resultDir +"/"+ "result_" + inputFiles[x]
            resulterrPath = resultDir+"/" + "err_" + inputFiles[x]

            command = "./"+codeDir+cppcode[:-4]

            testResult = excuteCode(command=command,
                                    inputFileName=inputPath,
                                    outputFileName=outputPath,
                                    resultFileName=resultPath,
                                    resultErrFileName=resulterrPath,
                                    maxTime=1)

            # Runtime Error
            if testResult=="Timeout":
                curResult.appendLog("Test Input :")
                curResult.appendLog(txtToStr(inputPath))
                curResult.setResult("TimeOut at Case %d" % x)
                break;
            elif testResult=="RuntimeError":
                curResult.appendLog("Test Input :")
                curResult.appendLog(txtToStr(inputPath))
                curResult.appendLog(txtToStr(resulterrPath))
                curResult.setResult("RunTime error at Case %d"%x)
                break;

            elif testResult=="Wrong Answer":
                curResult.appendLog("Test Input :")
                curResult.appendLog(txtToStr(inputPath))
                curResult.appendLog("%s output  : " %cppcode)
                curResult.appendLog(txtToStr(resultPath))
                curResult.appendLog("System output  : ")
                curResult.appendLog(txtToStr(outputPath))
                curResult.setResult("Wrong Answer at Case %d"%x)
                break;

        if curResult.result=="":
            curResult.setResult("Pass")

    return result


def resultToExcel(result):
    workbook = xlsxwriter.Workbook('Test_result.xlsx')
    worksheet = workbook.add_worksheet()

    worksheet.write(0, 0, "id")
    worksheet.write(0, 1, "result")
    worksheet.write(0, 2, "log")

    row=1
    for item in (result):
        worksheet.write(row, 0, item.id)
        worksheet.write(row, 1, item.result)
        worksheet.write(row, 2, item.log)
        row += 1

    # Write a total using a formula.
    # worksheet.write(row, 0, 'Total')
    # worksheet.write(row, 1, '=SUM(B1:B4)')

    workbook.close()


if __name__=="__main__":
    ProjectPath = os.path.abspath(".")
    TestPath = ProjectPath + "/Test1"
    os.chdir(TestPath)
    codeFiles,inputFiles,outputFiles = getFiles(TestPath)

    result = grading(codeFiles=codeFiles,inputFiles=inputFiles,outputFiles=outputFiles)
    resultToExcel(result)
