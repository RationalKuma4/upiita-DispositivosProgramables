################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
factfunc.obj: ../factfunc.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/c6000_7.4.24/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/Users/Luis Rene Alfonso/workspace_v8/DSP006_rutina_asm" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/ccsv8/tools/compiler/c6000_7.4.24/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/ti/ccsv8/tools/compiler/c6000_7.4.24/include" --define=c6713 --define=CHIP_6713 --diag_suppress=16002 --diag_wrap=off --diag_warning=225 --display_error_number --mem_model:data=near --preproc_with_compile --preproc_dependency="factfunc.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/c6000_7.4.24/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/Users/Luis Rene Alfonso/workspace_v8/DSP006_rutina_asm" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/ccsv8/tools/compiler/c6000_7.4.24/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/ti/ccsv8/tools/compiler/c6000_7.4.24/include" --define=c6713 --define=CHIP_6713 --diag_suppress=16002 --diag_wrap=off --diag_warning=225 --display_error_number --mem_model:data=near --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

sumfunc.obj: ../sumfunc.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/c6000_7.4.24/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/Users/Luis Rene Alfonso/workspace_v8/DSP006_rutina_asm" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/ccsv8/tools/compiler/c6000_7.4.24/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/ti/ccsv8/tools/compiler/c6000_7.4.24/include" --define=c6713 --define=CHIP_6713 --diag_suppress=16002 --diag_wrap=off --diag_warning=225 --display_error_number --mem_model:data=near --preproc_with_compile --preproc_dependency="sumfunc.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


