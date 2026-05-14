# Punctuation

 

[C++](https://cppreference.com/cpp)

 

[C++ language](https://cppreference.com/cpp/language)

 

[Basic Concepts](https://cppreference.com/cpp/language/basic_concepts)

 

These are the punctuation symbols in C++. The meaning of each symbol is detailed in the linked pages.

### Preprocessing operators

Preprocessing operators are recognized by [preprocessors](https://cppreference.com/cpp/preprocessor).

#### `#`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `%:`.

- Introduce a [preprocessing directive](https://cppreference.com/cpp/preprocessor).
- The [preprocessing operator for stringification](https://cppreference.com/cpp/preprocessor/replace##_and_##_operators).

#### `##`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `%:%:`.

- The [preprocessing operator for token pasting](https://cppreference.com/cpp/preprocessor/replace##_and_##_operators).

### Single-character operators and punctuators

#### `{` and `}`

[Alternative spellings](https://cppreference.com/cpp/language/operator_alternative) are `<%` and `%>` respectively.

- In a [class](https://cppreference.com/cpp/language/class) definition, delimit the [member specification](https://cppreference.com/cpp/language/class#Member_specification).
- In an [enumeration](https://cppreference.com/cpp/language/enum) definition, delimit the enumerator list.
- Delimit a [compound statement](https://cppreference.com/cpp/language/statements#Compound_statements). The compound statement may be part of



| a [lambda expression](https://cppreference.com/cpp/language/lambda) | (since C++11) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

- Part of the [aggregate initialization](https://cppreference.com/cpp/language/aggregate_initialization)(until C++11)[list-initialization](https://cppreference.com/cpp/language/list_initialization)(since C++11) syntax of an [initializer](https://cppreference.com/cpp/language/initialization).
- In a [namespace definition](https://cppreference.com/cpp/language/namespace), delimit the namespace body.
- In a [language linkage specification](https://cppreference.com/cpp/language/language_linkage), delimit the declarations.

| In a [`requires` expression](https://cppreference.com/cpp/language/constraints#Requires_expressions), delimit the requirements.In a [compound requirement](https://cppreference.com/cpp/language/constraints#Compound_Requirements), delimit the expression.In an [export declaration](https://cppreference.com/cpp/language/modules), delimit the declarations. | (since C++20) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

#### `[` and `]`

[Alternative spellings](https://cppreference.com/cpp/language/operator_alternative) are `<:` and `:>` respectively.

- [Subscript operator](https://cppreference.com/cpp/language/operator_member_access#Built-in_subscript_operator); part of `operator[]` in [operator overloading](https://cppreference.com/cpp/language/operators#Array_subscript_operator).
- Part of [array declarator](https://cppreference.com/cpp/language/declarations#Declarators) in a [declaration](https://cppreference.com/cpp/language/declarations) or a [type-id](https://cppreference.com/cpp/language/type#Type_naming) (e.g. in a [`new` expression](https://cppreference.com/cpp/language/new)).
- Part of `new[]` operator in [operator overloading (allocation function)](https://cppreference.com/cpp/memory/new/operator_new).
- Part of `delete[]` operator in [delete expression](https://cppreference.com/cpp/language/delete) and [operator overloading (deallocation function)](https://cppreference.com/cpp/memory/new/operator_delete).

| In a [lambda expression](https://cppreference.com/cpp/language/lambda), delimit the [captures](https://cppreference.com/cpp/language/lambda#Lambda_capture).In an [attribute specifier](https://cppreference.com/cpp/language/attributes), delimit the attributes. | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| In a [structured binding declaration](https://cppreference.com/cpp/language/structured_binding), delimit the identifier list. | (since C++17) |
| In a [pack indexing](https://cppreference.com/cpp/language/pack_indexing), delimit [converted constant expression](https://cppreference.com/cpp/language/constant_expression) representing an index. | (since C++26) |

#### `(` and `)`

- In an expression, [indicate grouping](https://cppreference.com/cpp/language/expressions#Primary_expressions).
- [Function call operator](https://cppreference.com/cpp/language/operator_other#Built-in_function_call_operator); part of `operator()` in [operator overloading](https://cppreference.com/cpp/language/operators#Function_call_operator).
- In a [function-style type cast](https://cppreference.com/cpp/language/explicit_cast), delimit the expression/initializers.
- In a [`static_cast`](https://cppreference.com/cpp/language/static_cast), [`const_cast`](https://cppreference.com/cpp/language/const_cast), [`reinterpret_cast`](https://cppreference.com/cpp/language/reinterpret_cast), or [`dynamic_cast`](https://cppreference.com/cpp/language/dynamic_cast), delimit the expression.
- Delimit the operand of the following operators:



| [`sizeof...`](https://cppreference.com/cpp/language/sizeof...)[`alignof`](https://cppreference.com/cpp/language/alignof)[`noexcept`](https://cppreference.com/cpp/language/noexcept) | (since C++11) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

- In a [placement `new` expression](https://cppreference.com/cpp/language/new), delimit the placement arguments.
- In a [`new` expression](https://cppreference.com/cpp/language/new), optionally delimit the type-id.
- In a [`new` expression](https://cppreference.com/cpp/language/new), delimit the initializers.
- In a [C-style cast](https://cppreference.com/cpp/language/explicit_cast), delimit the type-id.
- In a [declaration](https://cppreference.com/cpp/language/declarations) or a [type-id](https://cppreference.com/cpp/language/type#Type_naming), indicate grouping.
- Delimit the parameter list in



| a [lambda expression](https://cppreference.com/cpp/language/lambda) | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| a [user-defined deduction guide](https://cppreference.com/cpp/language/class_template_argument_deduction) | (since C++17) |
| a [`requires` expression](https://cppreference.com/cpp/language/constraints#Requires_expressions) | (since C++20) |

- Part of the [direct-initialization](https://cppreference.com/cpp/language/direct_initialization) syntax of an [initializer](https://cppreference.com/cpp/language/initialization).
- In an [asm declaration](https://cppreference.com/cpp/language/asm), delimit the string literal.
- In a [member initializer list](https://cppreference.com/cpp/language/initializer_list), delimit the initializers to a base or member.
- Delimit the controlling clause of a selection statement or iteration statement, including:



| [range-based `for`](https://cppreference.com/cpp/language/range-for) | (since C++11) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

- In a [handler](https://cppreference.com/cpp/language/catch), delimit the parameter declaration.
- In a [function-like macro definition](https://cppreference.com/cpp/preprocessor/replace#Function-like_macros), delimit the macro parameters.
- In a [function-like macro invocation](https://cppreference.com/cpp/preprocessor/replace#Function-like_macros), delimit the macro arguments or prevent commas from being interpreted as argument separators.
- Part of a `defined`, `__has_include`(since C++17), `__has_cpp_attribute`(since C++20) preprocessing operator.

| In a [`static_assert`](https://cppreference.com/cpp/language/static_assert) declaration, delimit the operands.Delimit the operand of the following specifiers:[`decltype`](https://cppreference.com/cpp/language/decltype)[`noexcept`](https://cppreference.com/cpp/language/noexcept_spec)[`alignas`](https://cppreference.com/cpp/language/alignas)[`explicit`](https://cppreference.com/cpp/language/explicit)(since C++20)In an [attribute](https://cppreference.com/cpp/language/attributes), delimit the attribute arguments. | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| Part of [`decltype(auto)`](https://cppreference.com/cpp/language/decltype) specifier. | (since C++14) |
| Delimit a [fold expression](https://cppreference.com/cpp/language/fold). | (since C++17) |
| Part of [`__VA_OPT__`](https://cppreference.com/cpp/preprocessor/replace) replacement in a variadic macro definition. | (since C++20) |

#### `;`

- Indicate the end of



| a [module declaration](https://cppreference.com/cpp/language/modules), import declaration, global module fragment introducer, or private module fragment introducera [requirement](https://cppreference.com/cpp/language/constraints#Requires_expressions) | (since C++20) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

- Separate the *condition* and *statement* of a [`for` statement](https://cppreference.com/cpp/language/for).

#### `:`

- Part of [conditional operator](https://cppreference.com/cpp/language/operator_other#Conditional_operator).
- Part of [label declaration](https://cppreference.com/cpp/language/statements#Labels).
- In the *base-clause* of a [class definition](https://cppreference.com/cpp/language/class), introduce the [base class](https://cppreference.com/cpp/language/derived_class).
- Part of [access specifier](https://cppreference.com/cpp/language/access) in member specification.
- In a [bit-field member declaration](https://cppreference.com/cpp/language/bit_field), introduce the width.
- In a [constructor](https://cppreference.com/cpp/language/constructor) definition, introduce the member initializer list.

| In a [range-based `for`](https://cppreference.com/cpp/language/range-for) statement, separate the *item-declaration* and the *range-initializer*.In the *enum-base* of an [enumeration declaration](https://cppreference.com/cpp/language/enum), introduce the underlying type. | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| In an [attribute specifier](https://cppreference.com/cpp/language/attributes), separate the *attribute-namespace* and the *attribute-list*. | (since C++17) |
| In a [module declaration](https://cppreference.com/cpp/language/modules) or import declaration of module partition, introduce the module partition name.Part of a [private module fragment](https://cppreference.com/cpp/language/modules#Private_module_fragment) introducer (`module :private;`). | (since C++20) |

#### `?`

- Part of [conditional operator](https://cppreference.com/cpp/language/operator_other#Conditional_operator).

#### `.`

- [Member access operator](https://cppreference.com/cpp/language/operator_member_access#Built-in_member_access_operators).

| In [aggregate initialization](https://cppreference.com/cpp/language/aggregate_initialization), introduce a designator.Part of [module name or module partition name](https://cppreference.com/cpp/language/modules). | (since C++20) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

#### `~`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `compl`.

- [Unary complement operator (a.k.a. bitwise not operator)](https://cppreference.com/cpp/language/operator_arithmetic#Bitwise_logic_operators); part of `operator~` in [operator overloading](https://cppreference.com/cpp/language/operators).
- Part of an [identifier expression](https://cppreference.com/cpp/language/identifiers) to name a [destructor](https://cppreference.com/cpp/language/destructor) or pseudo-destructor.

#### `!`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `not`.

- [Logical not operator](https://cppreference.com/cpp/language/operator_logical); part of `operator!` in [operator overloading](https://cppreference.com/cpp/language/operators).

| Part of [consteval if](https://cppreference.com/cpp/language/if#Consteval_if) statement. | (since C++23) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

#### `+`

- [Unary plus operator](https://cppreference.com/cpp/language/operator_arithmetic#Unary_arithmetic_operators); part of `operator+` in [operator overloading](https://cppreference.com/cpp/language/operators).
- [Binary plus operator](https://cppreference.com/cpp/language/operator_arithmetic#Additive_operators); part of `operator+` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `-`

- [Unary minus operator](https://cppreference.com/cpp/language/operator_arithmetic#Unary_arithmetic_operators); part of `operator-` in [operator overloading](https://cppreference.com/cpp/language/operators).
- [Binary minus operator](https://cppreference.com/cpp/language/operator_arithmetic#Additive_operators); part of `operator-` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `*`

- [Indirection operator](https://cppreference.com/cpp/language/operator_member_access#Built-in_indirection_operator); part of `operator*` in [operator overloading](https://cppreference.com/cpp/language/operators).
- [Multiplication operator](https://cppreference.com/cpp/language/operator_arithmetic#Multiplicative_operators); part of `operator*` in [operator overloading](https://cppreference.com/cpp/language/operators).
- Pointer operator or part of pointer-to-member operator in a [declarator](https://cppreference.com/cpp/language/declarations#Declarators) or in a [type-id](https://cppreference.com/cpp/language/type#Type_naming).

| Part of `*this` in a [lambda capture](https://cppreference.com/cpp/language/lambda#Lambda_capture) list, to capture the current object by copy. | (since C++17) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

#### `/`

- [Division operator](https://cppreference.com/cpp/language/operator_arithmetic#Multiplicative_operators); part of `operator/` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `%`

- [Modulo operator](https://cppreference.com/cpp/language/operator_arithmetic#Multiplicative_operators); part of `operator%` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `^`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `xor`.

- [Bitwise xor operator](https://cppreference.com/cpp/language/operator_arithmetic#Bitwise_logic_operators); part of `operator^` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `&`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `bitand`.

- [Address-of operator](https://cppreference.com/cpp/language/operator_member_access#Built-in_address-of_operator); part of `operator&` in [operator overloading](https://cppreference.com/cpp/language/operators#Rarely_overloaded_operators).
- [Bitwise and operator](https://cppreference.com/cpp/language/operator_arithmetic#Bitwise_logic_operators); part of `operator&` in [operator overloading](https://cppreference.com/cpp/language/operators).
- Lvalue-reference operator in a [declarator](https://cppreference.com/cpp/language/declarations#Declarators) or in a [type-id](https://cppreference.com/cpp/language/type#Type_naming).

| In a [lambda capture](https://cppreference.com/cpp/language/lambda#Lambda_capture), indicate by-reference capture.[Ref-qualifier](https://cppreference.com/cpp/language/member_functions#ref-qualified_member_functions) in [member function declaration](https://cppreference.com/cpp/language/member_functions). | (since C++11) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

#### `|`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `bitor`.

- [Bitwise or operator](https://cppreference.com/cpp/language/operator_arithmetic#Bitwise_logic_operators); part of `operator|` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `=`

- [Simple assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator=` in [operator overloading](https://cppreference.com/cpp/language/operators#Assignment_operator), which might be a special member function ([copy assignment operator](https://cppreference.com/cpp/language/copy_assignment)or [move assignment operator](https://cppreference.com/cpp/language/move_assignment)(since C++11)).
- Part of the [copy-initialization](https://cppreference.com/cpp/language/copy_initialization) and [aggregate initialization](https://cppreference.com/cpp/language/aggregate_initialization)(until C++11)[copy-list-initialization](https://cppreference.com/cpp/language/list_initialization)(since C++11) syntax of an [initializer](https://cppreference.com/cpp/language/initialization).
- In a [function declaration](https://cppreference.com/cpp/language/function), introduce a [default argument](https://cppreference.com/cpp/language/default_arguments).
- In a [template parameter list](https://cppreference.com/cpp/language/template_parameters), introduce a [default template argument](https://cppreference.com/cpp/language/template_parameters#Default_template_arguments).
- In a [namespace alias definition](https://cppreference.com/cpp/language/namespace_alias), separate the alias and the aliased namespace.
- In an [enum definition](https://cppreference.com/cpp/language/enum), introduce the value of enumerator.
- Part of *pure-specifier* in a [pure virtual function declaration](https://cppreference.com/cpp/language/abstract_class).

| Capture default in [lambda capture](https://cppreference.com/cpp/language/lambda#Lambda_capture), to indicate by-copy capture.Part of defaulted definition (`=default;`) or deleted definition (`=delete;`) in [function definition](https://cppreference.com/cpp/language/function#Function_definition).In a [type alias declaration](https://cppreference.com/cpp/language/type_alias), separate the alias and the aliased type. | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| In a [concept definition](https://cppreference.com/cpp/language/constraints), separate the concept name and the constraint expression. | (since C++20) |

#### `<`

- [Less-than operator](https://cppreference.com/cpp/language/operator_comparison); part of `operator<` in [operator overloading](https://cppreference.com/cpp/language/operators#Comparison_operators).
- In a [`static_cast`](https://cppreference.com/cpp/language/static_cast), [`const_cast`](https://cppreference.com/cpp/language/const_cast), [`reinterpret_cast`](https://cppreference.com/cpp/language/reinterpret_cast), or [`dynamic_cast`](https://cppreference.com/cpp/language/dynamic_cast), introduce the type-id.
- Introduce a [template argument list](https://cppreference.com/cpp/language/template_parameters#Template_arguments).
- Introduce a [template parameter list](https://cppreference.com/cpp/language/template_parameters) in



| a [lambda expression](https://cppreference.com/cpp/language/lambda) | (since C++20) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

- Part of `template<>` in [template specialization declaration](https://cppreference.com/cpp/language/template_specialization).
- Introduce a header name in



| a [`__has_include` preprocessing expression](https://cppreference.com/cpp/preprocessor/include) | (since C++17) |
| ------------------------------------------------------------ | ------------- |
| an [`import` declaration](https://cppreference.com/cpp/language/modules) | (since C++20) |

#### `>`

- [Greater-than operator](https://cppreference.com/cpp/language/operator_comparison); part of `operator>` in [operator overloading](https://cppreference.com/cpp/language/operators#Comparison_operators).
- [`static_cast`](https://cppreference.com/cpp/language/static_cast), [`const_cast`](https://cppreference.com/cpp/language/const_cast), [`reinterpret_cast`](https://cppreference.com/cpp/language/reinterpret_cast), or [`dynamic_cast`](https://cppreference.com/cpp/language/dynamic_cast), indicate the end of type-id.
- Indicate the end of a [template argument list](https://cppreference.com/cpp/language/template_parameters#Template_arguments).
- Indicate the end of a [template parameter list](https://cppreference.com/cpp/language/template_parameters) in



| a [lambda expression](https://cppreference.com/cpp/language/lambda) | (since C++20) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

- Part of `template<>` in [template specialization declaration](https://cppreference.com/cpp/language/template_specialization).
- Indicate the end of a header name in



| a [`__has_include` preprocessing expression](https://cppreference.com/cpp/preprocessor/include) | (since C++17) |
| ------------------------------------------------------------ | ------------- |
| an [`import` declaration](https://cppreference.com/cpp/language/modules) | (since C++20) |

#### `,`

- [Comma operator](https://cppreference.com/cpp/language/operator_other#Built-in_comma_operator); part of `operator,` in [operator overloading](https://cppreference.com/cpp/language/operators#Rarely_overloaded_operators).
- List separator in



| a [lambda capture](https://cppreference.com/cpp/language/lambda#Lambda_capture) listan [attribute](https://cppreference.com/cpp/language/attributes) list | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| the declarator list in a [using-declaration](https://cppreference.com/cpp/language/namespace#Using-declarations)the identifier list in a [structured binding](https://cppreference.com/cpp/language/structured_binding) declaration | (since C++17) |
| the argument list in a [multi-argument subscript expression](https://cppreference.com/cpp/language/operator_member_access#Built-in_subscript_operator) | (since C++23) |



| In a [`static_assert`](https://cppreference.com/cpp/language/static_assert) declaration, separate the arguments. | (since C++11) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

### Multi-character operators and punctuators

#### `[:` and `:]` (since C++26)

- Delimit a [splice specifier](https://cppreference.com/cpp/language/splice_specifiers).

#### `^^` (since C++26)

- [Reflection operator](https://cppreference.com/cpp/language/operator_reflection).

#### `...`

- In the [parameter list](https://cppreference.com/cpp/language/function#Parameter_list) of a function declarator or lambda expression(since C++11) or user-defined deduction guide(since C++17), signify a [variadic function](https://cppreference.com/cpp/language/variadic_arguments).
- In a [handler](https://cppreference.com/cpp/language/catch), signify catch-all handler.

| In a [macro definition](https://cppreference.com/cpp/preprocessor/replace), signify a variadic macro.Indicate [pack](https://cppreference.com/cpp/language/parameter_pack) declaration and expansion. | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| In [pack indexing](https://cppreference.com/cpp/language/pack_indexing#Syntax) expression and specifier. | (since C++26) |

#### `::`

- Scope resolution operator in



| In an [attribute](https://cppreference.com/cpp/language/attributes), indicate attribute scope. | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| Part of [nested namespace definition](https://cppreference.com/cpp/language/namespace). | (since C++17) |

#### `.*`

- [Pointer-to-member access operator](https://cppreference.com/cpp/language/operator_member_access#Built-in_pointer-to-member_access_operators).

#### `->`

- [Member access operator](https://cppreference.com/cpp/language/operator_member_access#Built-in_member_access_operators); part of `operator->` in [operator overloading](https://cppreference.com/cpp/language/operators).

| In a [function declarator](https://cppreference.com/cpp/language/function) or [lambda expression](https://cppreference.com/cpp/language/lambda), introduce the trailing return type. | (since C++11) |
| ------------------------------------------------------------ | ------------- |
| In a [user-defined deduction guide](https://cppreference.com/cpp/language/class_template_argument_deduction), introduce the result type. | (since C++17) |
| In a [compound requirement](https://cppreference.com/cpp/language/constraints#Compound_Requirements), introduce the return type requirement. | (since C++20) |

#### `->*`

- [Pointer-to-member access operator](https://cppreference.com/cpp/language/operator_member_access#Built-in_pointer-to-member_access_operators); part of `operator->*` in [operator overloading](https://cppreference.com/cpp/language/operators#Rarely_overloaded_operators).

#### `+=`

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator+=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `-=`

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator-=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `*=`

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator*=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `/=`

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator/=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `%=`

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator%=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `^=`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `xor_eq`.

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator^=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `&=`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `and_eq`.

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator&=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `|=`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `or_eq`.

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator|=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `==`

- [Equality operator](https://cppreference.com/cpp/language/operator_comparison); part of `operator==` in [operator overloading](https://cppreference.com/cpp/language/operators#Comparison_operators).

#### `!=`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `not_eq`.

- [Inequality operator](https://cppreference.com/cpp/language/operator_comparison); part of `operator!=` in [operator overloading](https://cppreference.com/cpp/language/operators#Comparison_operators).

#### `<=`

- [Less-than-or-equal-to operator](https://cppreference.com/cpp/language/operator_comparison); part of `operator<=` in [operator overloading](https://cppreference.com/cpp/language/operators#Comparison_operators).

#### `>=`

- [Greater-than-or-equal-to operator](https://cppreference.com/cpp/language/operator_comparison); part of `operator>=` in [operator overloading](https://cppreference.com/cpp/language/operators#Comparison_operators).

| `<=>`[Three-way comparison (spaceship) operator](https://cppreference.com/cpp/language/operator_comparison#Three-way_comparison); part of `operator<=>` in [operator overloading](https://cppreference.com/cpp/language/operators#Comparison_operators). | (since C++20) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

#### `&&`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `and`.

- [Logical and operator](https://cppreference.com/cpp/language/operator_logical); part of `operator&&` in [operator overloading](https://cppreference.com/cpp/language/operators#Rarely_overloaded_operators).

| Rvalue-reference operator in a [declarator](https://cppreference.com/cpp/language/declarations#Declarators) or in a [type-id](https://cppreference.com/cpp/language/type#Type_naming).[Ref-qualifier](https://cppreference.com/cpp/language/member_functions#ref-qualified_member_functions) in [member function declaration](https://cppreference.com/cpp/language/member_functions). | (since C++11) |
| ------------------------------------------------------------ | ------------- |
|                                                              |               |

#### `||`

[Alternative spelling](https://cppreference.com/cpp/language/operator_alternative) is `or`.

- [Logical or operator](https://cppreference.com/cpp/language/operator_logical); part of `operator||` in [operator overloading](https://cppreference.com/cpp/language/operators#Rarely_overloaded_operators).

#### `<<`

- [Bitwise shift operator](https://cppreference.com/cpp/language/operator_arithmetic#Bitwise_shift_operators); part of `operator<<` in operator overloading ([bitwise operator](https://cppreference.com/cpp/language/operators#Bitwise_arithmetic_operators) or [stream insertion operator](https://cppreference.com/cpp/language/operators#Stream_extraction_and_insertion)).

#### `>>`

- [Bitwise shift operator](https://cppreference.com/cpp/language/operator_arithmetic#Bitwise_shift_operators); part of `operator>>` in operator overloading ([bitwise operator](https://cppreference.com/cpp/language/operators#Bitwise_arithmetic_operators) or [stream extraction operator](https://cppreference.com/cpp/language/operators#Stream_extraction_and_insertion)).

#### `<<=`

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator<<=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `>>=`

- [Compound assignment operator](https://cppreference.com/cpp/language/operator_assignment); part of `operator>>=` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `++`

- [Increment operator](https://cppreference.com/cpp/language/operator_incdec); part of `operator++` in [operator overloading](https://cppreference.com/cpp/language/operators).

#### `--`

- [Decrement operator](https://cppreference.com/cpp/language/operator_incdec); part of `operator--` in [operator overloading](https://cppreference.com/cpp/language/operators).

### References

- C++23 standard (ISO/IEC 14882:2024):



- C++20 standard (ISO/IEC 14882:2020):



- C++17 standard (ISO/IEC 14882:2017):



- C++14 standard (ISO/IEC 14882:2014):



- C++11 standard (ISO/IEC 14882:2011):



- C++03 standard (ISO/IEC 14882:2003):



- C++98 standard (ISO/IEC 14882:1998):

