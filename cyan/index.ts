import { GlobType, StartTemplateWithLambda } from "@atomicloud/cyan-sdk";

StartTemplateWithLambda(async (i, d) => {

  const name = await i.text("What is your project binary's name?");
  const desc = await i.text("What is your project's description?");
  const author = await i.text("What is your project's author?");
  const licenseyear = await i.text("What year is your project licensed?");
  const email = await i.text("What is your project's author's email?");

  return {
    processors: [
      {
        name: "cyan/default",
        files: [
          {
            glob: "**/*",
            exclude: ["cyan/**/*", "scripts/**/*", ".github/workflows/publish.yaml", "cyan.yaml"],
            type: GlobType.Template,
          }
        ],
        config: {
          vars: {
            name,
            desc,
            author,
            licenseyear,
            email,
          }
        },
      },
    ],
    plugins: [

    ],
  }
});
