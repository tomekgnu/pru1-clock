################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: PRU Compiler'
	"/home/nanker/ti/ccs1110/ccs/tools/compiler/ti-cgt-pru_2.3.3/bin/clpru" -v3 --include_path="/home/nanker/ti/ccs1110/ccs/ccs_base/pru/include" --include_path="/home/nanker/workspace_v11/pru1-clock" --include_path="/home/nanker/ti/ccs1110/ccs/tools/compiler/ti-cgt-pru_2.3.3/include" --include_path="/home/nanker/workspace/beaglebone/pru-software-support-package-6.0.1/include" --include_path="/home/nanker/workspace/beaglebone/pru-software-support-package-6.0.1/include/am335x" --define=am3358 --define=pru1 -g --diag_warning=225 --diag_wrap=off --display_error_number --endian=little --hardware_mac=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: PRU Compiler'
	"/home/nanker/ti/ccs1110/ccs/tools/compiler/ti-cgt-pru_2.3.3/bin/clpru" -v3 --include_path="/home/nanker/ti/ccs1110/ccs/ccs_base/pru/include" --include_path="/home/nanker/workspace_v11/pru1-clock" --include_path="/home/nanker/ti/ccs1110/ccs/tools/compiler/ti-cgt-pru_2.3.3/include" --include_path="/home/nanker/workspace/beaglebone/pru-software-support-package-6.0.1/include" --include_path="/home/nanker/workspace/beaglebone/pru-software-support-package-6.0.1/include/am335x" --define=am3358 --define=pru1 -g --diag_warning=225 --diag_wrap=off --display_error_number --endian=little --hardware_mac=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


