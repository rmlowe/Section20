.PHONY: clean All

All:
	@echo "----------Building project:[ ClassTemplateArray - Debug ]----------"
	@cd "ClassTemplateArray" && "$(MAKE)" -f  "ClassTemplateArray.mk"
clean:
	@echo "----------Cleaning project:[ ClassTemplateArray - Debug ]----------"
	@cd "ClassTemplateArray" && "$(MAKE)" -f  "ClassTemplateArray.mk" clean
