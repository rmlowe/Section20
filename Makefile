.PHONY: clean All

All:
	@echo "----------Building project:[ FunctionTemplates - Debug ]----------"
	@cd "FunctionTemplates" && "$(MAKE)" -f  "FunctionTemplates.mk"
clean:
	@echo "----------Cleaning project:[ FunctionTemplates - Debug ]----------"
	@cd "FunctionTemplates" && "$(MAKE)" -f  "FunctionTemplates.mk" clean
