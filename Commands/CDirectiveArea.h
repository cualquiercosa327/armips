#pragma once

#include "Commands/CAssemblerCommand.h"
#include "Core/Expression.h"

class CDirectiveArea: public CAssemblerCommand
{
public:
	CDirectiveArea(bool shared, Expression& size);
	virtual bool Validate();
	virtual void Encode() const;
	virtual void writeTempData(TempData& tempData) const;
	virtual void writeSymData(SymbolData& symData) const;
	void setFillExpression(Expression& exp);
	void setPositionExpression(Expression& exp);
	void setContent(std::unique_ptr<CAssemblerCommand> content) { this->content = std::move(content); }
private:
	bool shared;
	int64_t position;
	Expression sizeExpression;
	int64_t areaSize;
	int64_t contentSize;
	Expression fillExpression;
	int8_t fillValue;
	Expression positionExpression;
	std::unique_ptr<CAssemblerCommand> content;
};

class CDirectiveAutoRegion : public CAssemblerCommand
{
public:
	CDirectiveAutoRegion();
	virtual bool Validate();
	virtual void Encode() const;
	virtual void writeTempData(TempData& tempData) const;
	virtual void writeSymData(SymbolData& symData) const;
	void setMinRangeExpression(Expression& exp);
	void setRangeExpressions(Expression& minExp, Expression& maxExp);
	void setContent(std::unique_ptr<CAssemblerCommand> content) { this->content = std::move(content); }

private:
	int64_t resetPosition;
	int64_t position;
	int64_t contentSize;
	Expression minRangeExpression;
	Expression maxRangeExpression;
	std::unique_ptr<CAssemblerCommand> content;
};
