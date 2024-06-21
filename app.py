from mako.template import Template
from mako.lookup import TemplateLookup

def generate_file_from_template(template_filename, output_filename, context):
    # 设置模板查找路径
    lookup = TemplateLookup(directories=['./templates/'])
    # template = Template(filename=template_filename, lookup=lookup)
    template = lookup.get_template(template_filename)
    # 渲染模板
    rendered_content = template.render(**context)

    # 将渲染后的内容写入输出文件
    with open(output_filename, 'w', encoding='utf-8') as file:
        file.write(rendered_content)

    print(f"File {output_filename} generated successfully.")

# generate_file_from_template('./templates/list.html', "./out/list.html", {"items": ['apple', 'banana', 'cherry']})
generate_file_from_template('a.txt.mako', "./out/a.txt", {"name": "yhifif", "age": 27, "hobby": "sleep"})
