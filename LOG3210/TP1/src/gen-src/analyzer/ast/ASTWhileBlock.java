/* Generated By:JJTree: Do not edit this line. ASTWhileBlock.java Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
package analyzer.ast;

public
class ASTWhileBlock extends SimpleNode {
  public ASTWhileBlock(int id) {
    super(id);
  }

  public ASTWhileBlock(Parser p, int id) {
    super(p, id);
  }


  /** Accept the visitor. **/
  public Object jjtAccept(ParserVisitor visitor, Object data) {

    return
    visitor.visit(this, data);
  }
}
/* JavaCC - OriginalChecksum=571e355cef0a5d6c37dd457e8b0e821d (do not edit this line) */
