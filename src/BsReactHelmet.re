type htmlAttributes;
type bodyAttributes;
type titleAttributes;
type meta;
type base;
type link;
type style;
type script;
type noscript;

[@bs.module "react-helmet"] [@react.component]
external make:
  (
    ~defer: bool=?,
    ~encodeSpecialCharacters: bool=?,
    ~onChangeClientState: unit => unit=?,
    ~htmlAttributes: htmlAttributes=?,
    ~bodyAttributes: bodyAttributes=?,
    ~titleAttributes: titleAttributes=?,
    ~defaultTitle: string=?,
    ~titleTemplate: string=?,
    // some <head> tags can be passed as props
    ~base: base=?,
    ~title: string=?,
    ~meta: array(meta)=?,
    ~link: array(link)=?,
    ~style: array(style)=?,
    ~script: array(script)=?,
    ~noscript: array(noscript)=?,
    ~children: React.element=?
  ) =>
  React.element =
  "";
